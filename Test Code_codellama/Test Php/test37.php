public function ajaxProcessDeleteModule()
{
    $moduleId = Tools::getValue('module_id');
    $categoryId = Tools::getValue('category_id');

    $module = new Module($moduleId);
    $category = new Category($categoryId);

    if (!$module->isDeletable()) {
        $this->errors[] = $this->l('The module cannot be deleted.');
        return;
    }

    if (!$category->isDeletable()) {
        $this->errors[] = $this->l('The category cannot be deleted.');
        return;
    }

    if (!$module->delete()) {
        $this->errors[] = $this->l('The module could not be deleted.');
        return;
    }

    if (!$category->delete()) {
        $this->errors[] = $this->l('The category could not be deleted.');
        return;
    }

    $this->json['success'] = true;