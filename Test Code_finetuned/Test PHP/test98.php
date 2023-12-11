public function store(Request $request)
{
    // Validate the incoming data
    $validatedData = $request->validate([
        'name' =>'required|string|max:255',
        'email' =>'required|email|unique:users,email',
       'service_id' =>'required|exists:services,id',
        'province_id' =>'required|exists:provinces,id',
    ]);

    // Create a new user record
    $user = User::create([
        'name' => $validatedData['name'],
        'email' => $validatedData['email'],
        'password' => Hash::make($validatedData['password']), // You should hash the password before storing it
    ]);

    // Associate the user with the selected service and province
    $user->services()->attach($validatedData['service_id']);
    $user->provinces()->attach($validatedData['province_id']);

    // Redirect to a success page
    return redirect()->route('registration.success')->with('success', 'User registered successfully');
}