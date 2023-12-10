    };

    template <class F>
    struct SendFunctor {
        F f;

        SendFunctor(F&& _rf)
            : f{std::forward<F>(_rf)}
        {
        }

        void operator()(ThisT& _rthis, ReactorContext& _rctx)
        {
            if (!_rctx.error()) {
                f(_rthis, _rctx);
            }
        }
    };
