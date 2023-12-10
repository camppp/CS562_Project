void LoanHoliday::annualReset() {
    if (_pParams->nMonthsPerYear <= _pParams->nMonthsTermRemaining) {
        _pParams->nMonthsYearRemaining = _pParams->nMonthsPerYear;
    } else {
        _pParams->nMonthsYearRemaining = _pParams->nMonthsTermRemaining;
    }
}
