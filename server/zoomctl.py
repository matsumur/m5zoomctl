from flask import Flask, render_template
import os

app = Flask(__name__)

@app.route('/')
def index():
  return render_template('index.html')

@app.route('/a')
def audioCtl():
  os.system("osascript -l JavaScript -e \"Application('zoom.us').activate(); const se = Application('System Events'); delay(0.1); se.keystroke('a', { using: ['command down', 'shift down']});\"")
  return render_template('index.html')

@app.route('/v')
def videoCtl():
  os.system("osascript -l JavaScript -e \"Application('zoom.us').activate(); const se = Application('System Events'); delay(0.1); se.keystroke('v', { using: ['command down', 'shift down']});\"")
  return render_template('index.html')

@app.route('/z')
def zoomActivate():
  os.system("osascript -l JavaScript -e \"Application('zoom.us').activate();\"")
  return render_template('index.html')

if __name__ == '__main__':
  app.run(host='0.0.0.0')