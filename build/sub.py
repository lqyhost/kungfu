def initialize(context):
    context.add_md(source=SOURCE.XTP)
    context.subscribe(tickers=["600000","300001"], source=SOURCE.XTP)

def on_tick(context, md, source, rcv_time):
    context.log_info("on_tick: (InstrumentID){} (UpdateTime){} (UpdateMillisec){} (LP){} (AP1){} (AV1){} (BP1){} (BV1){} (V){}".format(md.InstrumentID, md.UpdateTime, md.UpdateMillisec,md.LastPrice, md.AskPrice1, md.AskVolume1, md.BidPrice1, md.BidVolume1, md.Volume))