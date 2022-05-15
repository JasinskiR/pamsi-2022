import pandas as pd

df = pd.read_csv('dane.csv', sep=',')
df.dropna(inplace=True)
df.drop('Unnamed: 0', inplace=True, axis=1)
df.to_csv('poo.csv')