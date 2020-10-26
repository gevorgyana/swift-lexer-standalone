It is important to know that I have used REALEASE-5.3 version of
Swift. I have experienced problem while linking to a more recent
version of Swift, as they have indeed chaged the code.

RTII is disabled, I don't need it, nobody needs it.

To compile, modify your -I and -L flags. You can just create
libraries/ in current directory and inflate Swift tar there.
For -I, you should checkout RELEASE-5.3 source code, and not only that!
You also need to have llvm! And not the original one, but Apple's fork :)
So you'd better rely on existing scripts:

- `git clone $SWIFT_REPO && git checkout $RELEASE-5.3`
- go to utils/update_checkout/update-checkout-config.json and set
  - `default-branch-scheme` to `main`
- then run `utils/update_checkout --clone` and it will go one level above
and clone the dependency repositories there
- then run `utils/build_scipt --skip-build` to generate everything that we
might need.
- then run `utils/gyb` on `.gyb` files that are not yet where they need
to be - you will see build errors and know what to look for. It is easily
done and could be automated.