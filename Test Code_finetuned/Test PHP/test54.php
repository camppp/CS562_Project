// layout.blade.php
<!DOCTYPE html>
<html>
<head>
    <title>My Website</title>
</head>
<body>
    <header>
        @yield('header')
    </header>
    <main>
        @yield('content')
    </main>
    <footer>
        @yield('footer')
    </footer>
</body>
</html>
// home.blade.php
@extends('layout')

@section('header')
    <h1>Welcome to My Website</h1>
@endsection

@section('content')
    <p>This is the main content of the home page.</p>
@endsection

@section('footer')
    <p>Copyright 2022</p>
@endsection