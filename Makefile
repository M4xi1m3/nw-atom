apps += Atom::App
app_headers += apps/atom/app.h

apps_src += $(addprefix apps/atom/,\
  app.cpp \
  atom_controller.cpp \
  atom_view.cpp \
)

app_images += apps/atom/atom_icon.png

i18n_files += $(call i18n_with_universal_for,atom/base)

$(eval $(call depends_on_image,apps/atom/app.cpp,apps/atom/atom_icon.png))
