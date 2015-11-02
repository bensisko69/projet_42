from django.conf.urls import patterns, include, url

from django.contrib import admin
admin.autodiscover()

urlpatterns = patterns('',
	url(r'^index/', include('app_ldap.urls', namespace='app_ldap')),
	url(r'^admin/', include(admin.site.urls)),
)
