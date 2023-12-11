<?php

namespace App;

use Illuminate\Database\Eloquent\Model;

class Company extends Model
{
    public function employees()
    {
        return $this->hasMany('App\Employee');
    }

    public function suppliers()
    {
        return $this->hasMany('App\Supplier');
    }

    public function sellers()
    {
        return $this->hasMany('App\Seller');
    }
}