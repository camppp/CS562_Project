python
import acmacs_py  # Assuming the acmacs_py module is available for use

def create_acmacs_chart(chart_model):
    chart_model['doc'] = "Acmacs backend"
    acmacs_py.chart(chart_model)
