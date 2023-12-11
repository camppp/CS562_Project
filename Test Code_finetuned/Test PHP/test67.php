class Report {
    public function display_search() {
        // Display search options
        return "Search options";
    }

    public function display_sidebar_search() {
        // Display sidebar search
        return "Sidebar search";
    }

    public function export_report() {
        // Export the report
        return "Report exported";
    }

    public function render_html($html) {
        // Render the HTML output
        return $html;
    }
}

class Renderer {
    public function export_select(Report $report) {
        // Export the report
        return $report->export_report();
    }
}

$report = new Report();
$reporthtml = "<div>Report HTML content</div>";
$renderer = new Renderer();

echo $report->display_search();
echo $report->display_sidebar_search();
echo $renderer->export_select($report);
echo $report->render_html($reporthtml);