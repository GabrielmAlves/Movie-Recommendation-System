from flask import Flask, jsonify
from google.oauth2 import service_account
import google.auth
from google.auth.transport import requests

app = Flask(__name__)

@app.route("/token", methods=["GET"])

def get_token():
    credentials = service_account.Credentials.from_service_account_file(
        "C:/Users/Usuario/Downloads/movie-recommendation-sys-caa01-firebase-adminsdk-fbsvc-c1208fcf49.json",
        scopes=["https://www.googleapis.com/auth/datastore"]
    )
    
    credentials.refresh(google.auth.transport.requests.Request())
    return jsonify(access_token=credentials.token)

app.run(host="0.0.0.0", port=6000)

