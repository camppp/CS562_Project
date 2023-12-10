template<typename... Ret>
struct MakeTuple {
    typedef std::tuple<Ret...> type;
};
