from flask import abort

def process_mcq_data(repository, id, response):
    if'summary' in response:
        repository.update(id, response['mcqs'])
    else:
        abort(404, 'Call this API after summary has been generated')