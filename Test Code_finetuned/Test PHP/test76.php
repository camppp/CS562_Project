<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;
use App\Admin;
use Alert;

class AdminController extends Controller
{
    public function index()
    {
        return view('admin.addAdmin');
    }

    public function store(Request $request)
    {
        $this->validate($request, [
            'name' =>'required',
            'email' =>'required|email|unique:admins',
            'password' =>'required|min:6',
        ]);

        $admin = new Admin();
        $admin->name = $request->name;
        $admin->email = $request->email;
        $admin->password = bcrypt($request->password);
        $admin->save();

        Alert::success('Success', 'Admin account has been added successfully');

        return redirect()->route('admin.index');
    }

    public function edit_Admin($id)
    {
        $admin = Admin::find($id);

        return view('admin.editAdmin', compact('admin'));
    }

    public function edit_akun_admin(Request $request, $id)
    {
        $this->validate($request, [
            'name' =>'required',
            'email' =>'required|email|unique:admins,email,'.$id,
            'password' => 'nullable|min:6',
        ]);

        $admin = Admin::find($id);
        $admin->name = $request->name;
        $admin->email = $request->email;
        if($request->password) {
            $admin->password = bcrypt($request->password);
        }
        $admin->save();

        Alert::success('Success', 'Admin account has been updated successfully');

        return redirect()->route('admin.index');
    }
}