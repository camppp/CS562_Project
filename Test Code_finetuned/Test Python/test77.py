import torch
import torch.nn as nn
import torch.nn.functional as F

class Custom3DLayer(nn.Module):
    def __init__(self, in_filters, out_filters, gaussian_kernel, has_dropout, has_bn, has_gaussian_filter):
        super(Custom3DLayer, self).__init__()
        self.conv = nn.Conv3d(in_filters, out_filters, kernel_size=(gaussian_kernel, gaussian_kernel, gaussian_kernel))
        self.dropout = nn.Dropout3d(p=0.25) if has_dropout else None
        self.bn = nn.BatchNorm3d(out_filters, momentum=0.8) if has_bn else None
        self.gaussian_filter = nn.Conv3d(out_filters, out_filters, kernel_size=(gaussian_kernel, gaussian_kernel, gaussian_kernel)) if has_gaussian_filter else None

    def forward(self, x):
        x = self.conv(x)
        x = F.leaky_relu(x, negative_slope=0.2)
        if self.dropout:
            x = self.dropout(x)
        if self.bn:
            x = self.bn(x)
        if self.gaussian_filter:
            x = self.gaussian_filter(x)
        return x