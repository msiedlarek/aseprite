// Aseprite
// Copyright (C) 2001-2015  David Capello
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License version 2 as
// published by the Free Software Foundation.

#ifndef APP_UI_BUTTON_SET_H_INCLUDED
#define APP_UI_BUTTON_SET_H_INCLUDED
#pragma once

#include "base/signal.h"
#include "ui/grid.h"

#include <string>

namespace app {

  class ButtonSet : public ui::Grid {
  public:
    class Item : public ui::Widget {
    public:
      Item();
      void setIcon(she::Surface* icon);
      ButtonSet* buttonSet();
    protected:
      void onPaint(ui::PaintEvent& ev) override;
      bool onProcessMessage(ui::Message* msg) override;
      void onPreferredSize(ui::PreferredSizeEvent& ev) override;
    private:
      she::Surface* m_icon;
    };

    ButtonSet(int columns);

    void addItem(she::Surface* icon, int hspan = 1, int vspan = 1);
    Item* getItem(int index);

    int selectedItem() const;
    void setSelectedItem(int index);
    void setSelectedItem(Item* item);
    void deselectItems();

    void setOfferCapture(bool state);

    Signal0<void> ItemChange;

  protected:
    virtual void onItemChange();

  private:
    Item* findSelectedItem() const;

    bool m_offerCapture;
  };

} // namespace app

#endif
