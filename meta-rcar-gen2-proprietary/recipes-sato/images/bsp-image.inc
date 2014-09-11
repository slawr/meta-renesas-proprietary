MULTIMEDIA_INSTALL = '${@base_conditional( "MULTIMEDIA_ENABLE", "1", "${MULTIMEDIA_TP_ENABLE}", "0", d )}'
IMAGE_INSTALL_append = '${@base_conditional( "MULTIMEDIA_INSTALL", "1", " mmngr-tp-user-module \
                                                                          mmngrbuf-tp-user-module \
                                                                          vspm-tp-user-module \
                                                                          s3ctl-tp-user-module \
                                                                          fdpm-tp-user-module", \
                                                                          "", d )}'

MULTIMEDIA_PKGS = " mmngr-kernel-module mmngrbuf-kernel-module mmngr-user-module mmngrbuf-user-module \
					fdpm-kernel-module fdpm-user-module vspm-kernel-module \
					vspm-user-module s3ctl-kernel-module s3ctl-user-module uvcs-kernel-module omx-user-module"

IMAGE_INSTALL_append = '${@ "${MULTIMEDIA_PKGS}" if ${MULTIMEDIA_ENABLE} == 1 or ${DTV_ENABLE} == 1 else ""}'

# Append more package and gstreamer1.0 plugins with proprietary
IMAGE_INSTALL += " gstreamer1.0-omx "

IMAGE_INSTALL += '${@base_conditional("WAYLAND_ENABLE", "1", " gstreamer1.0-plugins-bad-waylandsink \
															gstreamer1.0-libav ", \
															"gstreamer1.0-plugins-good-video4linux2", d)}'

IMAGE_INSTALL += '${@base_conditional("WAYLAND_GFX_ENABLE", "1", " gstreamer1.0-plugins-base-vspfilter ", "", d)}'

# Append for wayland package
IMAGE_INSTALL += '${@base_conditional("WAYLAND_ENABLE", "1", " weston \
                                                               weston-init \
                                                               weston-examples \
                                                               wayland \
                                                               ", "", d)}'

IMAGE_INSTALL += '${@base_conditional("WAYLAND_GFX_ENABLE", "1", " libdrm-kms \
                                                                   wayland-wsegl \
                                                                   wayland-wsegl-dev \
                                                                   libegl \
                                                                   libgbm \
                                                                   libgbm-dev \
                                                                   ldd \
                                                                   ", "", d)}'

# Add DTV packages to image
IMAGE_INSTALL_append += '${@base_conditional( "DTV_ENABLE", "1", " scu-kernel-module ssp-kernel-module dtv dtv-dev dtv-staticdev", "", d )}'
