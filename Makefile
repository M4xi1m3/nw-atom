apps += Atom::App
app_headers += apps/atom/app.h

app_src += $(addprefix apps/atom/,\
  app.cpp \
  atom_controller.cpp \
  atom_view.cpp \
)

app_images += apps/atom/atom_icon.png

i18n_files += $(addprefix apps/atom/,\
	base.de.i18n\
	base.en.i18n\
	base.es.i18n\
	base.fr.i18n\
	base.pt.i18n\
)

$(eval $(call depends_on_image,apps/atom/app.cpp,apps/atom/atom_icon.png))
