public function ajaxProcessDeleteModule()
{
    // Check if the request is an AJAX request
    if (!Tools::isSubmit('ajax')) {
        die(json_encode(['error' => 'Invalid request']));
    }

    // Get the module id and category id from the request
    $moduleId = Tools::getValue('moduleId');
    $categoryId = Tools::getValue('categoryId');

    // Check if the module id and category id are valid
    if (!$moduleId ||!$categoryId) {
        die(json_encode(['error' => 'Invalid module or category id']));
    }

    // Perform the deletion operation
    try {
        // Assuming Module and Category classes have a deleteModuleFromCategory method
        Module::deleteModuleFromCategory($moduleId, $categoryId);
    } catch (Exception $e) {
        die(json_encode(['error' => $e->getMessage()]));
    }

    // Return a JSON response indicating the success of the operation
    die(json_encode(['success' => true]));
}