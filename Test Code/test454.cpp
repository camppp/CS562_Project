python
import xml.etree.ElementTree as ET

def parse_xml_input(xml_input: str) -> dict:
    result = {}
    root = ET.fromstring(xml_input)
    for port in root.findall('port'):
        port_id = port.get('id')
        precision = port.get('precision')
        dim = int(port.find('dim').text)
        result[port_id] = (precision, dim)
    return result
