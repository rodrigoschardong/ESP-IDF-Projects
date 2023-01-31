from flask import Flask, Response


class EndpointAction(object):

    def __init__(self, action):
        self.action = action
        self.response = Response(status=200, headers={})

    def __call__(self, *args):
        self.action()
        return self.response


class FlaskAppWrapper(object):
    app = None

    def __init__(self, name):
        self.app = Flask(name)

    def run(self):
        self.app.run()

    def add_endpoint(self, endpoint=None, endpoint_name=None, handler=None):
        self.app.add_url_rule(endpoint, endpoint_name, EndpointAction(handler))
        #add more urls


def action():
    # Execute anything
    pass

if __name__ == '__main__':
    a = FlaskAppWrapper('wrap')
    a.add_endpoint(endpoint='/ad', endpoint_name='ad', handler=action)
    a.run()