#pragma once
 
#include <iostream>
#include "Support_A_Dessin.h"
 
class TextViewer : public SupportADessin {
public:
 TextViewer(std::ostream& flot)
    : flot(flot)
  {}
  virtual ~TextViewer() = default;
  // on ne copie pas les TextViewer
  TextViewer(TextViewer const&)            = delete; 
  TextViewer& operator=(TextViewer const&) = delete;
   // mais on peut les déplacer
  TextViewer(TextViewer&&)            = default; 
  TextViewer& operator=(TextViewer&&) = default;
 
  virtual void dessine(Contenu const& a_dessiner) override;
 
private:
  std::ostream& flot;
};
