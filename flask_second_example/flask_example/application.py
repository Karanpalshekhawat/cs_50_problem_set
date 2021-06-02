from cs50 import SQL
from flask import Flask, render_template, request, redirect
from flask_mail import Mail, Message
import os

app = Flask(__name__)
app.config["MAIL_DEFAULT_SENDER"] = os.getenv("MAIL_DEFAULT_SENDER")
app.config["MAIL_PASSWORD"] = os.getenv("MAIL_PASSWORD")
app.config["MAIL_PORT"] = 587
app.config["MAIL_SERVER"] = "smtp.gmail.com"
app.config["MAIL_USE_TLS"] = True
app.config["MAIL_USERNAME"] = os.getenv("MAIL_USERNAME")
mail = Mail(app)

db = SQL("sqlite:///froshims.db")

SPORTS = [
    "Dodgeball",
    "Flag Football",
    "Soccer",
    "Volleyball",
    "Ultimate Frisbee"
]

#REGISTRANTS = {}


@app.route("/", methods=["GET", "POST"])
def index():
    return render_template("index.html", sports=SPORTS)

@app.route("/register", methods=["POST"])
def register():
    email = request.form.get("email")
    if not email:
        return render_template("failure.html", error="Email is not mentioned")
    sport = request.form.get("sport")
    if not sport:
        return render_template("failure.html", error="Sport is not mentioned")
    if sport not in SPORTS:
        return render_template("failure.html", error="Please select the one of the sport that is applicable")

    #REGISTRANTS[name] = sport
    message = Message("You are registered", recipients=[email])
    mail.send(message)

    return render_template("success.html")


@app.route("/registrants")
def registrants():
    #REGISTRANTS = db.execute("SELECT * from registrants")
    return render_template("registrants.html", registrants=REGISTRANTS)

