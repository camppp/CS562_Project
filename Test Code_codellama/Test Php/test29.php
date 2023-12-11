<?php

namespace MyApp\Exceptions;

use Exception;
use Throwable;

/**
 * Custom exception class for source not found
 */
class SourceNotFoundException extends Exception implements ExceptionInterface
{
    // No additional methods or properties need to be added
}

throw new SourceNotFoundException('Source not found');