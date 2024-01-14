import requests as rq

if __name__ == "__main__" :
    end_point = r"https://min-api.cryptocompare.com/data/price?fsym=BTC&tsyms=USD,JPY,EUR"

    response = rq.get(end_point)

    print(response.content)