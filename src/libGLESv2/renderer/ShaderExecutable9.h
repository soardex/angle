//
// Copyright (c) 2012 The ANGLE Project Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
//

// ShaderExecutable9.h: Defines a D3D9-specific class to contain shader
// executable implementation details.

#ifndef LIBGLESV2_RENDERER_SHADEREXECUTABLE9_H_
#define LIBGLESV2_RENDERER_SHADEREXECUTABLE9_H_

#include <d3d9.h>

#include "libGLESv2/renderer/ShaderExecutable.h"
#include "libGLESv2/D3DConstantTable.h"

namespace rx
{

class ShaderExecutable9 : public ShaderExecutable
{
  public:
    ShaderExecutable9(const void *function, size_t length, IDirect3DPixelShader9 *executable, gl::D3DConstantTable *constantTable);
    ShaderExecutable9(const void *function, size_t length, IDirect3DVertexShader9 *executable, gl::D3DConstantTable *constantTable);
    virtual ~ShaderExecutable9();

    static ShaderExecutable9 *makeShaderExecutable9(ShaderExecutable *executable);

    IDirect3DPixelShader9 *getPixelShader();
    IDirect3DVertexShader9 *getVertexShader();
    virtual gl::D3DConstantTable *getConstantTable();

  private:
    DISALLOW_COPY_AND_ASSIGN(ShaderExecutable9);

    IDirect3DPixelShader9 *mPixelExecutable;
    IDirect3DVertexShader9 *mVertexExecutable;

    gl::D3DConstantTable *mConstantTable;
};

}

#endif // LIBGLESV2_RENDERER_SHADEREXECUTABLE9_H_