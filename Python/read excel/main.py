import pandas as pd

import utils

excel_file = pd.read_excel("/home/joao/Desktop/Sample_-_Superstore.xls")

# print(excel_file)

print(utils.row_id_validator(excel_file))


print(utils.email_validator(excel_file))


print(utils.sales_validator(excel_file))

