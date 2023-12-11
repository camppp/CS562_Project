function generateProgressBar(label, percent) {
    return `
        <div class="col-xs-6 col-md-3">
            <div class="panel panel-default">
                <div class="panel-body easypiechart-panel">
                    <h4>${label}:</h4>
                    <div class="easypiechart" id="easypiechart-blue" data-percent="${percent}">
                        <span class="percent">${percent}%</span>
                    </div>
                </div>
            </div>
        </div>
    `;
}