from flask import Flask, Response, render_template


class EndpointAction(object):

    def __init__(self, action):
        self.action = action
        self.response = Response(status=200, headers={})

    def __call__(self, *args, **kwargs):
        response = self.action(*args, **kwargs)
        if Response != None:
            return response
        else:
            return self.response


class FlaskAppWrapper(object):
    app = None

    def __init__(self, name):
        self.app = Flask(name)

    def run(self):
        self.app.run(debug=True)

    def add_endpoint(self, endpoint=None, endpoint_name=None, handler=None, req_method = None):
        self.app.add_url_rule(endpoint, endpoint_name, EndpointAction(handler), methods = req_method)


def action():
    # Execute anything
    pass

def WebPage():
    return render_template('index.html')

def Param(param):
    out = f'Message: {param}'
    return out

if __name__ == '__main__':
    a = FlaskAppWrapper('wrap')
    #a.add_endpoint(endpoint='/ad', endpoint_name='ad', handler=action)
    a.add_endpoint(endpoint='/', endpoint_name='', handler=WebPage, req_method=['GET'])
    a.add_endpoint(endpoint='/<param>', endpoint_name='parametric_action', handler=Param, req_method=['GET'])
    a.run()