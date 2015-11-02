./manage.py collectstatic --noinput
uwsgi --socket /tmp/Framework2.sock --module mysite.wsgi