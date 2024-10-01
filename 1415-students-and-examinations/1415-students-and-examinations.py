import pandas as pd

def students_and_examinations(students: pd.DataFrame, subjects: pd.DataFrame, examinations: pd.DataFrame) -> pd.DataFrame:
    return pd.merge(
        left=pd.merge(students.sort_values('student_id'), subjects.sort_values('subject_name'), how='cross'),
        right=examinations.groupby(by=['student_id', 'subject_name']).size().reset_index(name='attended_exams'),
        how='left',
        on=['student_id', 'subject_name']
    ).fillna({'attended_exams': 0})