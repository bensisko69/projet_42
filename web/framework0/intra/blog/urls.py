from django.conf.urls import patterns, include, url
from . import views

urlpatterns = patterns('',
	url(r'^$', views.post_index),
	url(r'^post/(?P<pk>[0-9]+)/$', views.post_detail),
	url(r'^post/new/$', views.post_new, name='post_new'),
	url(r'^post/(?P<pk>[0-9]+)/edit/$', views.post_edit, name='post_edit'),
	url(r'^logout/', views.post_logout, name='post_logout'),
	url(r'^register$', views.register, name='register'),
	url(r'^register_user', views.register_user, name='register_user'),
	url(r'^registration_user', views.registration_user, name='registration_user'),
	url(r'^registration', views.registration, name='registration'),
	url(r'^post_list$', views.post_list, name='post_list'),
	url(r'^contact_user', views.send_contact, name='send_contact'),
	url(r'^contact', views.contact, name='contact'),
)