from django.db import models
from django.db.models import Sum

class Supply(models.Model):
    # Other fields and model definitions

    def calculate_total_connector_count(self):
        total_count = self.connectors.aggregate(total_count=Sum('supplyconnectorrelation__count'))['total_count']
        return total_count if total_count is not None else 0