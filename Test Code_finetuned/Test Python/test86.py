import aiohttp
import asyncio
from datetime import datetime

class SourceUpToDatenessCollector:
    async def _api_url(self) -> str:
        raise NotImplementedError

class JenkinsPluginSourceUpToDatenessCollector(SourceUpToDatenessCollector):
    async def _api_url(self) -> str:
        base_url = await super()._api_url()
        return f"{base_url}/lastSuccessfulBuild/api/json"

    async def _parse_source_response_date_time(self, response: aiohttp.ClientResponse) -> datetime:
        data = await response.json()
        timestamp = data['timestamp']
        return datetime.fromtimestamp(timestamp / 1000)