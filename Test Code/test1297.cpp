if (sparse) {
    param.sparse = DeformableConv::Param::Sparse::SPARSE;
    param.filter_shape = Shape({batch, 2 * deformable_group * fh * fw, oh, ow});
    param.offset_shape = Shape({batch, deformable_group * fh * fw, oh, ow});
} else {
    param.sparse = DeformableConv::Param::Sparse::DENSE;
    param.filter_shape = Shape({batch, deformable_group * fh * fw, oh, ow});
}
