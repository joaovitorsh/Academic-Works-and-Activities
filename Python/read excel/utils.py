import pandas as pd
from validate_email import validate_email

valid_emails = pd.DataFrame()


def row_id_validator(document):  # this function was made to validate the items in column A using the isinstance()
    # function and then storing all the "non-integers" in a list
    id_list = list(document['row_id'])
    bad_cell_id = []

    for i, row in enumerate(id_list):
        if not isinstance(row, int):
            bad_cell_id.append({"row": i, "column": "row_id", "value": row})

    return bad_cell_id


def email_validator(document):  # this function is designed to validate the items in column G using the
    # "validate_email" library and then store all non-email items in a list
    email_list = list(document['email'])
    bad_cell_email = []

    for i, row in enumerate(email_list):
        v = validate_email(f'{row}')
        if not v:
            bad_cell_email.append({"row": i, "column": "email", "value": row})

    return bad_cell_email


def sales_validator(document):  # this function was made to validate the items in the "sales" column using the
    # isinstance() function, but I didn't find an alternative to validate correctly
    sales_list = list(document['sales'])
    bad_cell_sales = []

    for i, row in enumerate(sales_list):
        if not isinstance(row, float):
            bad_cell_sales.append({"row": i, "column": "row_id", "value": row})

    return bad_cell_sales
