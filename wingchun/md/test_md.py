import json

engine = None

def ctp():
    global engine
    import libctpmd
    engine = libctpmd.Engine()
    info = {
            "FrontUri":"tcp://180.168.146.187:10011",
            "UserId":"118036",
            "BrokerId":"9999",
            "Password":"wangxi123"
        }
    engine.init(json.dumps(info))
    engine.start()

def tora():
    global engine
    import libtoramd
    engine = libtoramd.Engine()
    info = {
      "Password": "192535",
      "UserId": "316000032117",
      "FrontUri": "tcp://101.230.222.25:46402"
    }
    engine.init(json.dumps(info))
    engine.start()