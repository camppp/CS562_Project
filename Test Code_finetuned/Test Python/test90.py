def find_view(url_path: str) -> str:
    url_patterns = {
        '/home': 'home_view',
        '/get_professors/<str:professor_name>': 'get_professors_view',
        '/get_students/<str:student_name>': 'get_students_view',
        '/get_student_grades/<str:student_name>': 'get_student_grades_view',
        '/get_professor_students/<str:professor_name>': 'get_professor_students_view',
    }

    for pattern, view in url_patterns.items():
        if pattern == url_path:
            return view

    return "Not Found"