/*
 * gst-rtp-vp8-pay.h - Header for GstRtpVP8Pay
 * Copyright (C) 2011 Sjoerd Simons <sjoerd@luon.net>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */

#ifndef __GST_RTP_VP8_PAY_H__
#define __GST_RTP_VP8_PAY_H__

#include <glib-object.h>
#include <gst/base/gstadapter.h>
#include <gst/rtp/gstbasertppayload.h>

G_BEGIN_DECLS typedef struct _GstRtpVP8Pay GstRtpVP8Pay;
typedef struct _GstRtpVP8PayClass GstRtpVP8PayClass;

struct _GstRtpVP8PayClass
{
  GstBaseRTPPayloadClass parent_class;
};

struct _GstRtpVP8Pay
{
  GstBaseRTPPayload parent;
  gboolean is_keyframe;
  gint n_partitions;
  guint header_size;
  /* Add the end offset for easier implementation */
  guint partition_offset[9];
  guint partition_size[8];
};

GType gst_rtp_vp8_pay_get_type (void);

/* TYPE MACROS */
#define GST_TYPE_RTP_VP8_PAY \
  (gst_rtp_vp8_pay_get_type())
#define GST_RTP_VP8_PAY(obj) \
  (G_TYPE_CHECK_INSTANCE_CAST((obj), GST_TYPE_RTP_VP8_PAY, GstRtpVP8Pay))
#define GST_RTP_VP8_PAY_CLASS(klass) \
  (G_TYPE_CHECK_CLASS_CAST((klass), GST_TYPE_RTP_VP8_PAY, GstRtpVP8PayClass))
#define GST_IS_RTP_VP8_PAY(obj) \
  (G_TYPE_CHECK_INSTANCE_TYPE((obj), GST_TYPE_RTP_VP8_PAY))
#define GST_IS_RTP_VP8_PAY_CLASS(klass) \
  (G_TYPE_CHECK_CLASS_TYPE((klass), GST_TYPE_RTP_VP8_PAY))
#define GST_RTP_VP8_PAY_GET_CLASS(obj) \
  (G_TYPE_INSTANCE_GET_CLASS ((obj), GST_TYPE_RTP_VP8_PAY, GstRtpVP8PayClass))

gboolean gst_rtp_vp8_pay_plugin_init (GstPlugin * plugin);

G_END_DECLS
#endif /* #ifndef __GST_RTP_VP8_PAY_H__ */
