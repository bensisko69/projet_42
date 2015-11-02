from django.db import models
from django import forms
from django.utils import timezone

class Post(models.Model):
	author = models.ForeignKey('auth.User')
	title = models.CharField(max_length=200)
	text = models.TextField()
	created_date = models.DateTimeField(default=timezone.now)
	published_date = models.DateTimeField(blank=True, null=True)
	def publish(self):
		self.published_date = timezone.now()
		self.save()
	def __str__(self):
		return self.title

class User(models.Model):
	username = models.CharField(max_length=200)
	password = models.CharField(max_length=50)

class NewUser(models.Model):
	username = models.CharField(max_length=200)
	firstname = models.CharField(max_length=200)
	lastname = models.CharField(max_length=200)
	email = models.EmailField(max_length=200)
	password = models.CharField(max_length=50)
	def __str__(self):
		return self.username

class Contact(models.Model):
	username = models.CharField(max_length=200)
	obj = models.CharField(max_length=200)
	text = models.TextField()
	def __str__(self):
		return self.obj
