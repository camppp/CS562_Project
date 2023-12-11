public function rules()
{
    return [
        [['task_id', 'path'],'required'],
        [['task_id'], 'integer'],
        [['path'],'string','max' => 255],
        [['path'], 'unique', 'targetAttribute' => ['task_id', 'path'],'message' => 'The file path has already been taken.'],
    ];
}