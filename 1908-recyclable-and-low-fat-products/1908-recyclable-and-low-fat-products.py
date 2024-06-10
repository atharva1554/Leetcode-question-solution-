import pandas as pd

def find_products(products: pd.DataFrame) -> pd.DataFrame:
    df=products[products['low_fats']=='Y']
    df=df[df['recyclable']=='Y']
     
    return df.drop(['low_fats','recyclable'],axis=1)