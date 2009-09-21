#ifndef __DICTIONARYBAR_HH_INCLUDED__
#define __DICTIONARYBAR_HH_INCLUDED__

#include <QToolBar>
#include <QSize>
#include "dictionary.hh"
#include "config.hh"

/// A bar containing dictionary icons of the currently chosen group.
/// Individual dictionaries can be toggled on and off.
class DictionaryBar: public QToolBar
{
  Q_OBJECT

public:

  /// Constructs an empty dictionary bar
  DictionaryBar( QWidget * parent,
                 Config::MutedDictionaries & mutedDictionaries,
                 Config::Events & );

  /// Sets dictionaries to be displayed in the bar. Their statuses (enabled/
  /// disabled) are taken from the configuration data.
  void setDictionaries( std::vector< sptr< Dictionary::Class > > const & );

private:

  Config::MutedDictionaries & mutedDictionaries;
  Config::Events & configEvents;

private slots:

  void dictionaryMuted( QString const & );
  void dictionaryUnmuted( QString const & );

  void actionWasTriggered( QAction * );
};

#endif