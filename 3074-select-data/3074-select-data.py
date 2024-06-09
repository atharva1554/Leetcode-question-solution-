import pandas as pd

def selectData(students: pd.DataFrame) -> pd.DataFrame:
    a=students[students['student_id']==101]
    a=a.drop(columns='student_id')
    return a
    
    