from django.conf.urls import patterns, url, include

from app_ldap import views

urlpatterns = patterns('',
    url(r'^$', views.index, name='index'),
    url(r'^identification/$', views.login_view, name='login_view'),
    url(r'^logout/$', views.logout_view, name='logout_view'),
    url(r'^directory/$', views.directory_view, name='directory_view'),
)