from django.shortcuts import render
from django.http import HttpResponseRedirect
from django.contrib.auth.forms import AuthenticationForm
from django.contrib.auth.models import User
from django.contrib.auth import authenticate, logout, login
from django.core.urlresolvers import reverse

from django_auth_ldap.backend import LDAPBackend


def index(request):
	return render(request, "index.html")

def login_view(request):
	if request.method == 'POST':
		form = AuthenticationForm(data=request.POST)
		if form.is_valid():
			username = request.POST['username']
			password = request.POST['password']
			user = authenticate(username=username, password=password)
			if user is not None:
				login(request, user)
			return HttpResponseRedirect(reverse('app_ldap:directory_view'))
	else:
		form = AuthenticationForm()
	return render(request, 'identification.html', {'form' : form})

def logout_view(request):
	logout(request)
	return index(request)

def directory_view(request):
	return render (request, 'directory.html')


