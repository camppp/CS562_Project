import json
import jsonpath

def extract_emr_studio_config(template: str) -> dict:
    # Parse the template as a JSON object
    template_json = json.loads(template)

    # Extract the EMR Studio configuration
    emr_studio_config = jsonpath.jsonpath(template_json, "$.Resources.MyEmrStudio")

    # Extract the required information
    auth_mode = emr_studio_config["Properties"]["AuthMode"]
    default_s3_location = emr_studio_config["Properties"]["DefaultS3Location"]
    engine_security_group_id = emr_studio_config["Properties"]["EngineSecurityGroupId"]
    name = emr_studio_config["Properties"]["Name"]