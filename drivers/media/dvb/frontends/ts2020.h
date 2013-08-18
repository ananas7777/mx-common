  /*
     Driver for Montage ts2020 DVBS Silicon tuner

     Copyright (C) 2012 Tomazzo Muzumici

     This program is free software; you can redistribute it and/or modify
     it under the terms of the GNU General Public License as published by
     the Free Software Foundation; either version 2 of the License, or
     (at your option) any later version.

     This program is distributed in the hope that it will be useful,
     but WITHOUT ANY WARRANTY; without even the implied warranty of
     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the

     GNU General Public License for more details.

     You should have received a copy of the GNU General Public License
     along with this program; if not, write to the Free Software
     Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.

  */

#ifndef __DVB_TS2020_H__
#define __DVB_TS2020_H__

#include <linux/i2c.h>
#include "dvb_frontend.h"

/**
 * Attach a ts2020 tuner to the supplied frontend structure.
 *
 * @param fe Frontend to attach to.
 * @param addr i2c address of the tuner.
 * @param i2c i2c adapter to use.
 * @param clk_out_div output clock divider
 * @return FE pointer on success, NULL on failure.
 */
#if defined(CONFIG_DVB_TS2020) || (defined(CONFIG_DVB_TS2020_MODULE) \
							&& defined(MODULE))
extern struct dvb_frontend *ts2020_attach(struct dvb_frontend *fe, int addr,
					struct i2c_adapter *i2c,
					u8 clk_out_div);
#else
static inline struct dvb_frontend *ts2020_attach(struct dvb_frontend *fe,
						int addr,
						struct i2c_adapter *i2c,
						u8 clk_out_div)
{
	printk(KERN_WARNING "%s: driver disabled by Kconfig\n", __func__);
	return NULL;
}
#endif /* CONFIG_DVB_TS2020 */

#endif /* __DVB_TS2020_H__ */
