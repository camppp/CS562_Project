import pybind11

def create_acmacs_chart(chart_model):
    # Set the documentation of the chart model to "Acmacs backend"
    chart_model['doc'] = "Acmacs backend"

    # Create an ACMACS backend chart using the modified chart model
    acmacs_chart = pybind11.chart(chart_model)

    # Return the created ACMACS backend chart
    return acmacs_chart
