<?php

namespace TagService\Api\Infrastructure;

use IA\Micro\BaseKernel;
use TagService\Api\Interfaces\TagServiceInterface;

class TagServiceKernel extends BaseKernel implements TagServiceInterface
{
    /**
     * @var array<string, mixed>
     */
    private array $config;

    /**
     * @var array<string, mixed>
     */
    private array $container;

    /**
     * @var array<string, mixed>
     */
    private array $services;

    /**
     * @var array<string, mixed>
     */
    private array $tags;

    /**
     * @var array<string, mixed>
     */
    private array $routes;

    /**
     * @var array<string, mixed>
     */
    private array $middleware;

    /**
     * @var array<string, mixed>