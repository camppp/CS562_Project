CREATE FUNCTION students_t_pdf(df DOUBLE, t DOUBLE)
RETURNS DOUBLE
AS $$
  DECLARE
    gamma_df DOUBLE;
    gamma_df_over_2 DOUBLE;
    gamma_df_plus_1_over_2 DOUBLE;
    result DOUBLE;
  BEGIN
    gamma_df := Gamma(df / 2);
    gamma_df_over_2 := Gamma(df / 2);
    gamma_df_plus_1_over_2 := Gamma((df + 1) / 2);
    result := (1 + t^2 / df)^(-(df + 1) / 2) / (sqrt(df * pi) * gamma_df_over_2 * gamma_df_plus_1_over_2);
    RETURN result;
  END;
$$ LANGUAGE plpgsql;
