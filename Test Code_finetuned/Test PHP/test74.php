import re

def extractBaseUrls(filePaths):
    baseUrls = set()
    for path in filePaths:
        match = re.search(r'<\?php echo (.+?);\?>', path)
        if match:
            baseUrls.add(match.group(1))
    return list(baseUrls)

filePaths = [
    '<?php echo Yii::app()->theme->baseUrl;?>/assets/js/jquery-ui.min.js',
    '<?php echo Yii::app()->theme->baseUrl;?>/assets/css/style.css',
    '<?php echo Yii::app()->theme->baseUrl;?>/assets/js/custom.js',
    '<?php echo Yii::app()->theme->baseUrl;?>/assets/images/logo.png',
]

print(extractBaseUrls(filePaths))