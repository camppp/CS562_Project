template <typename T>
struct is_arithmetic {
    static constexpr bool value = false;
};

template <typename T>
struct is_arithmetic<T*> {
    static constexpr bool value = true;
};

template <typename T>
struct is_arithmetic<T&> {
    static constexpr bool value = true;
};

template <typename T>
struct is_arithmetic<T&&> {
    static constexpr bool value = true;
};

template <typename T>
struct is_arithmetic<T[N]> {
    static constexpr bool value = true;
};

template <typename T>
struct is_arithmetic<T[M][N]> {
    static constexpr bool value = true;
};

template <typename T>
struct is_arithmetic<T[M][N][O]> {
    static constexpr bool value = true;
};

template <typename T>
struct is_arithmetic<T[M][N][O][P]> {
    static constexpr bool value = true;
};

template <typename T>
struct is_arithmetic<T[M][N][O][P][Q]> {
    static constexpr bool value = true;
};

template <typename T>
struct is_arithmetic<T[M][N][O][P][Q][R]> {
    static constexpr bool value = true;
};

template <typename T>
struct is_arithmetic<T[M][N][O][P][Q][R][S]> {
    static constexpr bool value = true;
};

template <typename T>
struct is_arithmetic<T[M][N][O][P][Q][R][S][T]> {
    static constexpr bool value = true;
};

template <typename T>
struct is_arithmetic<T[M][N][O][P][Q][R][S][T][U]> {
    static constexpr bool value = true;
};

template <typename T>
struct is_arithmetic<T[M][N][O][P][Q][R][S][T][U][V]> {
    static constexpr bool value = true;
};

template <typename T>
struct is_arithmetic<T[M][N][O][P][Q][R][S][T][U][V][W]> {
    static constexpr bool value = true;
};

template <typename T>
struct is_arithmetic<T[M][N][O][P][Q][R][S][T][U][V][W][X]> {
    static constexpr bool value = true;
};

template <typename T>
struct is_arithmetic<T[M][N][O][P][Q][R][S][T][U][V][W][X][Y]> {
    static constexpr bool value = true;
};

template <typename T>
struct is_arithmetic<T[M][N][O][P][Q][R][S][T][U][V][W][X][Y][Z]> {
    static constexpr bool value = true;
};
