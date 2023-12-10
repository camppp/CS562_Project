void operator()(ThisT& _rthis, ReactorContext& _rctx)
{
    if (!_rctx.error()) {
        f(_rthis, _rctx);
    }
}
